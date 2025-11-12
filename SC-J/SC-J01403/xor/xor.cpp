#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long a[N],b[N],n,k,m,s,s1,mx;
struct stu{
	int a,b;
}s2[N];
bool cmp(stu a,stu b){
	if(a.a=b.a){
		return a.b>b.b;
	}
	return a.a>b.a;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j]=b[j-1]^a[j];
			if(b[j]==k){
				s++;
				s2[j].a=i;
				s2[j].b=j;
			}
		}				
	}
	sort(s2+1,s2+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(s2[i].a==s2[i+1].a||s2[i].b>=s2[i+1].b||s2[i].b>=s2[i+1].a){
			s--;
		}
	}
	cout<<s;
	return 0;
}