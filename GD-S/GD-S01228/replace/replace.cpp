#include<bits/stdc++.h>
using namespace std;
string s[400005];
string c[400005];
int ab[30][30];
map<int,int>asd[400005];
int main(){
	freopen("relpace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(i%2==0){
			int j=1;
			while(s[i][j]!='\0'){
				ab[int(s[i-1][j])-96][int(s[i][j])-96]++;
				j++;
			}
			
		}
	}
	int b=0;
	for(int i=1;i<=m;i++){
		cin>>c[i];
		if(i%2==0){
			int j=1;
			while(c[i][j]!='\0'){
				if(c[i-1][j]!=c[i][j]&&ab[int(c[i-1][j])-96][int(c[i][j])-96]>0){
					ab[int(c[i-1][j])-96][int(c[i][j])-96]--;
					asd[i-1][j]++;
					b=max(asd[i-1][j],b);
				}
				j++;
			}
			
		}
		cout<<b<<endl;
		memset(asd,0,sizeof(0));
	}
	return 0;
} 
