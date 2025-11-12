#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000009];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	int n=s.size();
	int tot=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[tot]=(int(s[i])-48);
			tot+=1;
		}
	}
	sort(a,a+tot,cmp);
	for(int i=0;i<tot;i++){
		cout<<a[i];
	}
	return 0;
}
