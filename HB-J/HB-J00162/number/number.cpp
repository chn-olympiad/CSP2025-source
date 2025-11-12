#include<bits/stdc++.h>
using namespace std;
string s;
vector <int> a;
int su;
bool aa(int x,int y){
	return x>y;
}
void xx(){
	for(int i=0;i<int(a.size());i++){
		for(int j=i+1;j<int(a.size());j++){
			if(!aa(a[i],a[j])){
				int x=a[i];
				a[i]=a[j];
				a[j]=x;
			}
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<int(s.size());i++){
		if(s[i]>='0'&&s[i]<='9'){
			a.push_back(int(s[i]-'0'));
			
		}
	}
	xx();
	for(int i=0;i<int(a.size());i++){
		cout<<a[i];
	}
	return 0;
}
