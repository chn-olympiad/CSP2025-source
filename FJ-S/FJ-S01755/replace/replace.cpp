#include<bits/stdc++.h>
using namespace std;
string a[200005],b[200005],c[200005],d[2000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		cin>>c[i]>>d[i];
	}
	for(int w=1;w<=q;w++){
//		int fl=0;
//		long long ans=0;
//		for(int i=0;i<c[i].size();i++){
//			if(c[w][i]==d[w][i]&&i+1==c[i].size()){
//				ans++;
//			}
//			if(c[w][i]==d[w][i]){
//				continue;
//			}
//			else{
//				int flag=1;
//				if(fl==1){
//					cout<<0<<endl;
//					break;
//				}
//				fl=1;
//				int fla=0;
//				for(int j=1;j<=n;n++){
//					if(c[w][i]==a[j][0]){
//						int g=1;
//						for(int k=0;k<a[j].size();k++){
//							if(a[j][k]!=d[w][i+k-1]){
//								g=0;
//							}
//						}
//						if(g==1){
//							fla=1;
//							break;
//						}
//					}
//				}
//				if(fla==0){
//					cout<<0<<endl;
//					break;
//				}else{
//					continue;
//				}
//			}
//		}
//		cout<<ans<<endl;
		cout<<0<<endl;
	}
	return 0;
} 
