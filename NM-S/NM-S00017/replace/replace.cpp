#include<bits/stdc++.h>
using namespace std;
string a[3][100010];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[1][i]>>a[2][i];
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0;
		}else{
			int s=0;
			for(int j=0;j<=s1.size()-1;j++){
				for(int k=j;k<=s1.size()-1;k++){
					string s4;
					s4+=s1;
					string s3;
					for(int l=j;l<=k;l++){
						s3=s3+s1[l];
					}
					for(int l=1;l<=n;l++){
						cout<<s3<<' '<<a[1][l]<<endl;
						if(s3==a[1][l]){
							s3=a[2][l];
						}
						break;
					}
					for(int l=j;l<=k;l++){
						s4[l]=s3[l-j];
					}
					if(s4==s2){
						s++;
					}
				}
			}
			cout<<s<<endl;
		}
	}
	return 0;
}
