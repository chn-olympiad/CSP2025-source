#include<iostream>
#include<algorithm>
using namespace std;
string s;
int a[1000005],b[1000005],c[1000005];
int i;
//bool(int x,int y){
//	return x>y;
//}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for( i=1;i<=s;i++){
		if(a[i]>='0'&&a[i]<='9'){
			<char,int> a[i];
			b[i]=a[i];
			c[b[i]]++;
		}
	} 
//	sort(b,b+i,cmp);
for(int j=10000000;j<=s;j++){
	if(c[j]>0){
		cout<<j;
		break;
	}
}
	return 0;
} 
