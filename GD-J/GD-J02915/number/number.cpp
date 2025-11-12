#include<bits/stdc++.h>
using namespace std;
bool vmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string q;
	cin >> q;
	int a=0,s=0;
	char w[1000001]={};
	for(int i=0;i<q.size();i++){
		if(q[i]>='0' && q[i]<='9'){
			w[a]=q[i];
			a++;
		}
	}
	sort(w,w+a,vmp);
	cout << w;
	return 0;
} 
