#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("number.in");
	ofstream fout("number.out");
	string s;
//	cin>>s;
	//cout<<s<<endl;
	fin>>s;
	string c;
	int flag=0;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=10){
			;
		}else{
			c+=s[i];
		}
	}
	for(int i=0;i<c.size();i++){
		for(int j=i;j<c.size();j++){
			if(c[i]<c[j]){
				char t=c[j];
				c[j]=c[i];
				c[i]=t;
			}
		}
	}
	for(int i=0;i<c.size();i++){
		fout<<c[i];
//		cout<<c[i];
	}
	fin.close();
	fout.close();
	return 0;
}
