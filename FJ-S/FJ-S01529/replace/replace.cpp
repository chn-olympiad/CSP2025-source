#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,q;
string b[200005][2],a[200005][2];
bool has(string a,string b){
	for(int i=0;i<a.length();i++){
		if(a[i]==b[0]){
			bool is=true;
			for(int j=0,i2=i;j<b.length();j++,i2++){
				if(a[i2]!=b[j]){
					is=false;
				}
			}
			if(is){
				return true;
			}
		}
	}
	return false;
}
int has2(string a,string b){
	for(int i=0;i<a.length();i++){
		if(a[i]==b[0]){
			bool is=true;
			for(int j=0,i2=i;j<b.length();j++,i2++){
				if(a[i2]!=b[j]){
					is=false;
				}
			}
			if(is){
				return i;
			}
		}
	}
	return -1;
}
bool has3(string a,string b,string c,string d){
	if(has(a,b)&&has(c,d)&&has2(a,b)==has2(c,d)){
		string x1="",x2="",z1="",z2="";
		for(int i=0;i<has2(a,b);i++){
			x1+=a[i],x2+=c[i];
		}
		for(int i=has2(a,b)+b.length();i<a.length();i++){
			z1+=a[i],z2+=c[i];
		}
		if(x1==x2&&z1==z2){
			return true;
		}
		return false;
	}else{
		return false;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	int i=0; 
	while(i<n){
		scanf("%d%d",&b[i][0],&b[i][1]);
		i++;
	}
	i=0;
	while(q--){
		scanf("%d%d",&a[i][0],&a[i][1]);
		int ans=0;
		for(int j=0;j<n;j++){
			if(has3(a[i][0],b[j][0],b[i][1],b[j][1])){
				ans++; 
			}
		}
		cout<<ans<<endl;
		i++;
	}
	return 0;
}
