//GZ-S00324 六盘水市第四实验中学 王梓懿 
#include<bits/stdc++.h>
using namespace std;
int n,m,c[500],q,sum,p;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int j=0;j<n;j++){
	for(int i=j;i<n+j;i++){
		if(s[i%n]='0'&&q>=c[i]){
			q+=1;
		}else{
			p+=1;
		}
	}
	if(p>=m)sum++;}
	cout<<sum;
	return 0; 
}
