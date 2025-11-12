#include<bits/stdc++.h>
using namespace std;
string a;
int f[1000001];
int xt = 1;
/*       RP++!          */
bool cmp (int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i] >= '0' && a[i] <= '9'){
			f[xt++] = a[i] - '0';
		}
	}
	sort(f+1,f+xt,cmp);
	for(int i=1;i<xt;i++){
		cout<<f[i];
	}
	return 0;
}

