#include<bits/stdc++.h>
using namespace std;

struct D{
	int a1,a2,a3,k;
}d[500000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(d,0,sizeof(d));
		int n,s1=0,s2=0,s3=0;
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>d[i].a1>>d[i].a2>>d[i].a3;
			if(d[i].a1<d[i].a2&&d[i].a3<d[i].a2){
				s2++,d[i].k=2;
				ans+=d[i].a2;
			}
			else if(d[i].a1<d[i].a3&&d[i].a2<d[i].a3){
				s3++,d[i].k=3;
				ans+=d[i].a3;
			}
			else{
				s1++,d[i].k=1;
				ans+=d[i].a1;
			}
			
		}
		int e;
		vector<int> v;
		if(s1*2>n){
			e=s1;
			for(int i=1;i<=n;i++){
				if(d[i].k==1)
					v.push_back(d[i].a1-max(d[i].a2,d[i].a3));
			}
		}
		else if(s2*2>n){
			e=s2;
			for(int i=1;i<=n;i++){
				if(d[i].k==2)
					v.push_back(d[i].a2-max(d[i].a1,d[i].a3));
			}
		}
		else if(s3*2>n){
			e=s3;
			for(int i=1;i<=n;i++){
				if(d[i].k==3)
					v.push_back(d[i].a3-max(d[i].a2,d[i].a1));
			}
		}
		else{
			cout<<ans<<endl;
			continue;
		}
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();i++){ 
			if(e*2<=n){
				break;
			}
			ans-=v[i];
			e--;
			
		}
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
