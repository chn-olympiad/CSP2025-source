#include<iostream>
#include<algorithm>
using namespace std;
int n,m,s[100010][5],a=0,b=0,c=0,sum=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		sum=0,a=0,b=0,c=0;
		cin>>m;
		for(int j=1;j<=m;j++){
			cin>>s[j][1]>>s[j][2]>>s[j][3];
			int zd=max(s[j][1],max(s[j][2],s[j][3]));
			if(zd==s[j][1]){
				a++;
				sum+=s[j][1];
			}else if(zd==s[j][2]){
				b++;
				sum+=s[j][2];
			}else{
				c++;
				sum+=s[j][3];
			}
		}
		if(a<=n/2&&b<=n/2&&c<=n/2){
			cout<<sum<<endl;
		}
		
	}
	
	return 0;
} 
