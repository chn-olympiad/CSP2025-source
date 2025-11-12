#include<bits/stdc++.h>
using namespace std;
string s,a="";
int x[100],minx=9999,m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int j=0;j<s.size();j++){
		x[0]=s.find("0");
		x[1]=s.find("1");
		x[2]=s.find("2");
		x[3]=s.find("3");
		x[4]=s.find("4");
		x[5]=s.find("5");
		x[6]=s.find("6");
		x[7]=s.find("7");
		x[8]=s.find("8");
		x[9]=s.find("9");
		for(int i=1;i<=9;i++){
			if(x[i]<minx&&x[i]>=0){
				minx=x[i];
				s.erase(j,minx);
			}else continue;
		}
		
	
	}
	
	/*for(int i=0;i<=s.size();i++){
		if(s.substr(i,1)<s.substr(i+1,1)){
			s.replace(s.find(s.substr(i,1)),1,s.substr(i+1,1));
		}
	}*/
	cout<<s;
	return 0;
}

