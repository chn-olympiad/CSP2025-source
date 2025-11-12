#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a[n][2];
	string ques[q][2];
	for(int i = 0;i<n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	for(int i = 0;i<q;i++){
		cin>>ques[i][0]>>ques[i][1];
		if(ques[i][0].size()!=ques[i][1].size()){
			cout<<0<<endl;
		}
		else{
			int ans=0;
			for(int j = 0;j<n;j++){
				int len=a[j][0].size();
				int o=0;
				for(int k = 0;k<=(ques[j][0].size()-len);k++){
					for(int l = 0;l<len;l++){
						if(ques[i][0][k+l]==a[j][0][l]){
							o++;
						}
					}
					if(o>0&&o!=len){
						break;
					}
					else{
						int t=0;
						for(t = 0;t<len;t++){
							ques[i][0][k+t]=a[j][1][t];
						}
//						cout<<ques[i][0]<<' '<<ques[i][1]<<endl;
						if(ques[i][0]==ques[i][1]){
							ans++;
						}
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
