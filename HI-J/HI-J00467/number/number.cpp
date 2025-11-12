#include<bits/stdc++.h>
using namespace std;
string a;
long long b[10000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	long long j=0;
	for(long long i=0;i<a.size();i++){
		if(a[i]=='0'){
			b[j]=0;
			j++;
		}else if(a[i]=='1'){
			b[j]=1;
			j++;
		}else if(a[i]=='2'){
			b[j]=2;
			j++;
		}else if(a[i]=='3'){
			b[j]=3;
			j++;
		}else if(a[i]=='4'){
			b[j]=4;
			j++;
		}else if(a[i]=='5'){
			b[j]=5;
			j++;
		}else if(a[i]=='6'){
			b[j]=6;
			j++;
		}else if(a[i]=='7'){
			b[j]=7;
			j++;
		}else if(a[i]=='8'){
			b[j]=8;
			j++;
		}else if(a[i]=='9'){
			b[j]=9;
			j++;
		}
	}
	sort(b,b+j);
	for(long long i=j-1;i>=0;i--){
		printf("%lld",b[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
