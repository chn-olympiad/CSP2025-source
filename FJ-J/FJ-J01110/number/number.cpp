#include<bits/stdc++.h>
using namespace std;
int lb[17],n;
char a[200007];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	
	scanf("%s",&a);
	n=strlen(a);
	
	for(int i=0;i<n;i++) lb[a[i]-'0']++;
	
	for(int i=9;i>=0;i--){
		while(lb[i]--) printf("%d",i);
	}
	cout<<endl;
	return 0;
}
