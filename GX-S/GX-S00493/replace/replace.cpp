#include <iostream>
#include <string>
using namespace std;
string c[100005];
string d[100005];
int n,q;
int re(string a,string b,int co,int x){
	string a1,a2,a3;
	for(int i=0;i<n;i++){
		if(a.find(c[i],x)>=0&&a.find(c[i],x)<=a.length()){
			a1=a.substr(x,a.find(c[i],x));
			a2=a.substr(a.find(c[i],x)+c[i].length(),a.length()-1);
			//cout<<a1<<" "<<a2<<endl;
			a3+=a1+d[i]+a2;
			//cout<<c[i]<<endl;
			//cout<<a1<<" "<<a2<<" "<<a3<<" "<<b<<endl;
			if(a3==b){
				co++;
			}
			else{
				return re(a3,b,co,a.find(c[i],x)+c[i].length()-1);
			}
		}
	}
	return co;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>c[i]>>d[i];
	}
	string a,b;
	string a1,a2;
	for(int i=0;i<q;i++){
		cin>>a>>b;
		cout<<re(a,b,0,0)<<endl;
	}
	return 0;
}
