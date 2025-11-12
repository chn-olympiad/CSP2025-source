#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	long long lena=a.length();
	int b[100005];
	int r=0;
    for(int i=0;i<lena;i++){
    	if(a[i]>='0'&&a[i]<='9'){
    		b[r]=a[i]-'0';
    		r++;
		}
	}
	sort(b+0,b+r,cmp);
	for(int i=0;i<r;i++){
		cout<<b[i];
	}
	return 0;
} 

