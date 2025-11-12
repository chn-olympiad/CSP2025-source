#include<bits/stdc++.h>
using namespace std;
string a;
char m[1000005];
long long n,x=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]=='0'){
			m[i]=a[i];
			x++;
	}
		else if(a[i]=='1'){
			m[i]=a[i];
			x++;
		}
		else if(a[i]=='2'){
			m[i]=a[i];
			x++;
		}
		else if(a[i]=='3'){
			m[i]=a[i];
			x++;
		}
		else if(a[i]=='4'){
			m[i]=a[i];
			x++;
		}
		else if(a[i]=='5'){
			m[i]=a[i];
			x++;
		}
		else if(a[i]=='6'){
			m[i]=a[i];
			x++;
		}else if(a[i]=='7'){
			m[i]=a[i];
			x++;
		}else if(a[i]=='8'){
			m[i]=a[i];
			x++;
		}
		else if(a[i]=='9'){
			m[i]=a[i];
			x++;
		}
}
	sort(m,m+n,cmp);
	for(int i=0;i<x;i++){
		cout<<m[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
