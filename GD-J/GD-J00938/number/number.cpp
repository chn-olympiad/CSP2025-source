#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
} 
string n;
int m[1000005],j=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			m[j]=(int)(n[i]-'0');
			j++;
		}
	}
	sort(m,m+j+1,cmp);
	for(int i=0;i<j;i++){
		cout<<m[i];
	}
	return 0;
}
