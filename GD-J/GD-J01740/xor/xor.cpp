#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200005];
long long ans=0;
struct d{
	int l,r;
};
bool cmp(d a,d b){
	return a.r<b.r;
}
vector<d>p;
bool flag=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			flag=0;
		}
	}
	
	long long ans=0;
	if(k==0&&flag){
		for(int i=1;i<=n;i++){
			if(a[i]==1&&a[i+1]==1){
				ans++;
				i++;
			}else if(a[i]==0){
				ans++;
			}
		}
	}else if(k==1&&flag){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
	}else if(flag){
		ans=0;
	}
	if(flag){
		cout<<ans;
		return 0;
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			long long sum=0;
			for(int i=l;i<=r;i++){
				sum^=a[i];
			}
			if(sum==k){
				p.push_back({l,r});
				
			}
		}
	}
	sort(p.begin(),p.end(),cmp);
	int lastr;
	for(int i=0;i<p.size();i++){
		//cout<<p[i].r<<" "<<p[i].l<<endl;
		if(i==0){
			lastr=p[i].r;
			ans++;
			continue;
		}
		if(p[i].l<=lastr){
			continue;
		}else{
			ans++;
			lastr=p[i].r;
		}
		
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
