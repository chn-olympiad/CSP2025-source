#include<bits/stdc++.h>
using namespace std;
int t,n,m,cl1,cl2,cl3,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		ans=0;
		cin>>n;m=n/2;
		for(int j=0;j<n;j++){
			int c1,c2,c3,mc;
			cin>>c1>>c2>>c3;
			if(c1>c2&&c1>c3&&cl1<m)mc=c1,cl1++;
			else if(c2>c1&&c2>c1&&cl2<m)mc=c2,cl2++;
			else if(c3>c1&&c3>c2&&cl3<m)mc=c3,cl3++;
			else if(c1>c2&&c1>c3&&cl1>=m){
				if(c2>c3&&cl2<m)mc+=c2,cl2++;
				else mc+=c3,cl3++;
			}
			else if(c2>c1&&c2>c3&&cl2>=m){
				if(c1>c3&&cl1<m)mc+=c1,cl1++;
				else mc+=c3,cl3++;
			}
			else if(c3>c2&&c3>c1&&cl3>=m){
				if(c1>c2&&cl1<m)mc+=c1,cl1++;
				else mc+=c2,cl2++;
			}
			ans+=mc;
		}
		cout<<ans<<endl;
	}
}
