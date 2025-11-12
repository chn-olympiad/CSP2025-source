#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
string  s;
int a[1000000];
int e[100000];
int ss=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&s);
	char maxn=0;
	for(int i=0;i<=s.size();i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[i]=s[i];
			ss++;
		}
		for(int j=0;j<=ss;i++){
			if(a[i]==' '){
				a[i]=0;
				e[i]=a[i];
			}
			for(int j=ss;i>=1;i--){
				for(int g=0;g<=ss;j++){
					a[g]=a[j];
					if(e[i]>a[i]){
						a[i]=e[i];
					}
				}
			}		
		}
	}
}
