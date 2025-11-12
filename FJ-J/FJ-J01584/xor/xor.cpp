#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],sum=1;
vector<int> b;
vector<int> e;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool l=0,l2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) l=1;
		if(a[i]!=0||a[i]!=1) l2=1;
	}
	if(l==0){
		if(k==1){
			cout<<(1+n)*n/2;
		}else{
			cout<<0;
		}
		return 0;
	}else if(l2==0){
		int qp=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				bool r=0;
				for(int q=i;q<=j;q++){
					if(a[q]==1){
						r=1;
						break;
					}
				}
				if(r==0) qp++;
			}
		}
		if(k==0){
			cout<<qp;
		}else if(k==1){
			cout<<(1+n)*n/2-qp;
		}else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum=a[i];
			for(int q=i+1;q<=j;q++){
				sum=sum|a[k];
			}
			if(sum==k){
				b.push_back(i);
				e.push_back(j);
				
			}
			cout<<i<<" "<<j<<" "<<sum<<endl;
		}
	}
	for(int i=0;i<b.size();i++){
		cout<<b[i]<<" "<<e[i]<<endl;
	}
	for(int i=1;i<b.size();i++){
		bool p=0;
		for(int j=i;j<b.size();j++){
			if(e[j]<e[j-1] || e[j]==e[j-1]&&b[j]>b[j-1]){
				swap(e[j],e[j-1]);
				swap(b[j],b[j-1]);
				p=1;
			}
		}
		if(p=0) break;
	}
	
	int lis=e[0];
	for(int i=1;i<b.size();i++){
		if(lis<b[i]){
			sum++;
			lis=e[i];
		}
	}
	cout<<sum;
	return 0;
}
