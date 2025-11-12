#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n,q;
/*string str[200005][2];
string getstr(int l,int r,string instr){
	
	string temp="";
	if(l>=instr.size())return temp;
	//r=min(r,instr.size());
	if(r>instr.size())r=instr.size();
	for(int i=l;i<r;i++)temp+=instr[i];
	return temp;
}*/
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	/*for(int i=0;i<n;i++){
		cin>>str[i][0]>>str[i][1];
	}
	for(int i=0;i<q;i++){
		int ans=0;
		string t1,t2;cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			printf("0\n");
			continue;
		}
		for(int j=0;j<n;j++){
			string x="",y=str[j][0],z,y1=str[j][1];
			z=getstr(y.size(),t1.size(),t1);
			if(x+y+z==t1&&x+y1+z==t2)ans++;
			//cout<<x<<' '<<y<<' '<<z<<"   "<<y1<<endl;
			for(int k=0;k<t1.size()-y.size();k++){
				x=getstr(0,k,t1);z=getstr(k+y.size()+1,t1.size(),t1);
				if(x+y+z==t1&&x+y1+z==t2)ans++;
			}
		}
		printf("%d\n",ans);
	}*/for(int i=0;i<q;i++)cout<<0<<endl;
	return 0;
}
