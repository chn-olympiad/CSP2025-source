#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string a,b;
    long long int c=0,d[100000];
    cin >> a;
    for(int i=0;i < a.size();i++){
		if(a[i]>='0' && a[i]<='9'){
			b[c]=a[i];
			c++;
		}
	}
	for(int i=0;i < c;i++){
		d[i]=b[i]-48;
	}
	sort(d,d+c,cmp);
	for(int i=0;i < c;i++){
		cout << d[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
