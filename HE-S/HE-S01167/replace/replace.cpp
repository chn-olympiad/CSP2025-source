#include<iostream>
#include<cstring>
using namespace std;
int n,q,ans=0;
string shx1,shx2,qq,rr,qqq,rrr,mp[2][200005],xx,xxx,zz,zzz;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>mp[0][i]>>mp[1][i];
	}
	for(int i=0;i<q;i++){
		cin>>qq>>qqq;
		for(int j=0;j<qq.size()-1;j++){
			for(int z=j+1;z<qq.size();z++){
				xx=qq.substr(0,j);
				xxx=qqq.substr(0,j);
				rr=qq.substr(j,z-j+1);
				rrr=qqq.substr(j,z-j+1);
				zz=qq.substr(z+1,qq.size()-z-1);
				zzz=qqq.substr(z+1,qqq.size()-z-1);
				for(int f=0;f<n;f++){
					if(rr==mp[0][f]&&mp[1][f]==rrr&&xx==xxx&&zz==zzz){
						ans++;
					}
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
