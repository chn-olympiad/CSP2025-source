#include<bits/stdc++.h>
using namespace std;
char b[1000000];
long long c=0;
string a;
bool pa(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>a;
    for(long long i=0;i<a.size();i++){
    	if(a[i]>='0'&&a[i]<='9'){
    		b[c]=a[i];
    		c++;
		}
	}
	sort(b,b+c,pa);
	for(long long i=0;i<c;i++){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
return 0;
} 
