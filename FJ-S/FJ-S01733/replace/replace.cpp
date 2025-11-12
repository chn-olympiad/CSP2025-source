#include <bits/stdc++.h>
using namespace std;
string s1[5005],s2[5005],t1[5005],t2[5005];
unsigned long long ha1[5005][5005],ha2[5005][5005],hat[50005],har[50005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>t1[i]>>t2[i];
		int sum=0;
		for(int j=t1[i].size()-1;j>=0;j--){
    		hat[i]+=(unsigned long long)(t1[i][j]*pow(131,sum));
    		sum++;
		}
		sum=0;
		for(int j=t2[i].size()-1;j>=0;j--){
    		har[i]+=(unsigned long long)(t2[i][j]*pow(131,sum));
    		sum++;
		}
	}
	for(int i=1;i<=q;i++){
    	cin>>s1[i]>>s2[i];
    	int sum=0,cnt=0;
    	for(int j=s1[i].size()-1;j>=0;j--){
    		ha1[i][s1[i].size()-j]=(unsigned long long)(s1[i][j]*pow(131,sum)+ha1[i][s1[i].size()-j-1]);
    		sum++;
		}
		sum=0;
		for(int j=s2[i].size()-1;j>=0;j--){
    		ha2[i][s2[i].size()-j]=(unsigned long long)(s2[i][j]*pow(131,sum)+ha2[i][s2[i].size()-j-1]);
    		sum++;
		}
		for(int j=1;j<=s1[i].size();j++){
			for(int k=0;k<j;k++){
				for(int l=1;l<=n;l++){
					if(ha1[i][j]-ha1[i][k]==hat[l]&&ha2[i][j]-ha2[i][k]==har[l]){
						cnt++;
					}
				}
			}
		}
		cout<<cnt<<'\n';
	}
}
