#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","s",stdout);
	int m;
	int a[10001];
	int t=1;
	string n;
	cin>>n;
	m=n.size();
	for(int i=0;i<m;i++){
		if(n[i]>='0' && n[i]<='9'){
			a[t]=n[i]-'0';
			t++;
		}
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++){
		cout<<a[i];
	}
	fclose(stdin);
    fclose(stdout);
}
