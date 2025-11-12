#include<bits/stdc++.h>
using namespace std;
string a;
int b[100001],d=1;
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int c=a.size();
	for(int i=0;i<=c-1;i++){
		if(a[i]>='0'&&a[i]<='9'){
			d++;
			int e=(int)(a[i])-'0';
			b[d]=e;
		}
	}
	sort(b+1,b+d+1);
	for(int i=d;i>=2;i--){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
