#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string a[300000][4],b[300000][4],a1,b1;
int n,place,q;
long long answer;
string re(string a,string b,int l){
	string x="",y="";
	int lenb=b.length(),lena=a.length();
	if(lenb+l<lena)y=a.substr(l+lenb,lena-l-lenb);
	if(l!=0) x=a.substr(0,l);
	return x+b+y;
	 
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][1];
		cin>>a[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>b[i][1];
		cin>>b[i][2];
	}
	string ce="1";
	for(int i=1;i<=q;i++){
		answer=0;
		for(int d=1;d<=n;d++){
			b1=b[i][2];
			place=int(b1.find(a[d][2]));
			while(place!=-1){
				if(b[i][1]==re(b1,a[d][1],place)){
					answer++;
				}
				b1=re(b1,ce,place);
				place=int(b1.find(a[d][2]));
			}
			
		}
		cout<<answer<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
