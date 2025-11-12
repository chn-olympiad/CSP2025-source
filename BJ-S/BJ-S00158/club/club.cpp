#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n][3];
		int ac2[n],bc2[n],cc[n];
		int ab[2*n],ac[2*n],bc[2*n];
		int as=0,bs=0,cs=0,an=0,bn=0,cn=0;
		for(int i=0;i<n;++i)cin>>a[i][0]>>a[i][1]>>a[i][2];
		for(int i=0;i<n;++i){
			ac[i]=0,bc[i]=0,cc[i]=0;
			int maxx=max(a[i][0],max(a[i][1],a[i][2]));
			if(a[i][0]==maxx){as++,an+=maxx,ac[i]=1e9;//cout<<"aaaaaaaaaaaaaaa"<<i;
				}
			else if(a[i][1]==maxx){bs++,bn+=maxx,bc[i]=1e9;//cout<<"bbbbbbbbbbbbbbbb"<<i;
				}
			else if(a[i][2]==maxx){cs++,cn+=maxx,cc[i]=1e9;//cout<<"cccccccccccccc"<<i;
				}
			if(ac[i]!=1e9)ac[i]=maxx-a[i][0];
			if(bc[i]!=1e9)bc[i]=maxx-a[i][1];
			if(cc[i]!=1e9)cc[i]=maxx-a[i][2];
			//cout<<an<<" "<<bn<<" "<<cn<<endl;
			//cout<<ac[i]<<" "<<bc[i]<<" "<<cc[i]<<" "<<maxx<<endl;
		}
		if(as<=n/2&&bs<=n/2&&cs<=n/2){
		cout<<an+bn+cn<<endl;}
		else{
			int sm=0;
			int maxx=max(as,max(bs,cs));
			if(as==maxx){
				//sort(bc,bc+n);
				//sort(cc,cc+n);
				for(int i=0;i<2*n;++i){
					if(i<n){
						if(ac[i]==1e9)bc2[i]=bc[i];
						else bc2[i]=1e9;
					}
					else {
						if(ac[i-n]==1e9)bc2[i]=cc[i-n];
						else bc2[i]=1e9;
					}
				}
				sort(bc2,bc2+2*n);
				for(int i=0;i<as-n/2;++i){
					sm+=bc2[i];
					//cout<<" >>>>>>>>>>>>>>>AA>>>>>>>>>>>>>>>>>>>"<<bc2[i]<<endl;
				}
			}
			if(bs==maxx){
				//sort(ac,ac+n);
				//sort(cc,cc+n);
				for(int i=0;i<2*n;++i){
					if(i<n){
						if(bc[i]==1e9)ac2[i]=ac[i];
						else ac2[i]=1e9;
					}
					else {
						if(bc[i-n]==1e9)ac2[i]=cc[i-n];
						else ac2[i]=1e9;
					}
				}
				sort(ac2,ac2+2*n);
				for(int i=0;i<bs-n/2;++i){
					sm+=ac2[i];
					//<<" >>>>>>>>>>>>>>BB>>>>>>>>>>>>>>>>>>>>"<<ac2[i]<<endl;
				}
				//sm=1e9;
				//cout<<ac2[0];
			}
			if(cs==maxx){
				//sort(ac,ac+n);
				//sort(bc,bc+n);
				for(int i=0;i<2*n;++i){
					if(i<n){
						if(cc[i]==1e9)ab[i]=ac[i];
						else ab[i]=1e9;
						//cout<<"<<<<<<<<<<,cc>>>>>>>>>>>>>::::"<<ab[i]<<endl;
					}
					else {
						if(cc[i-n]==1e9)ab[i]=bc[i-n];
						else ab[i]=1e9;
						//cout<<"<<<<<<<<<<,cc>>>>>>>>>>>>>::::"<<ab[i]<<endl;
					}
				}
				sort(ab,ab+2*n);
				for(int i=0;i<cs-n/2;++i){
					sm+=ab[i];
					//cout<<" >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<ab[i]<<endl;
				}
			}
			cout<<an+bn+cn-sm<<endl;
		}
		//cout<<n<<endl;
	}
	return 0;
}
