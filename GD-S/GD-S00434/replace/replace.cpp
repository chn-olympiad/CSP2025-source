#include<string>
#include<iostream>
using namespace std;
int n,q;
struct str{
	string a,b;
} str[1000005],que[1000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>str[i].a>>str[i].b;
	}
	for(int i=1;i<=q;i++){
		cin>>que[i].a>>que[i].b;
		int sum=0;
		string now=que[i].a;
		for(int j=1;j<=n;j++){
			for(int l=0;l<now.length();l++){
				if(now[l]==str[j].a[0]){
					for(int p=0;p<str[j].a.length();p++){
						now[l+p]=str[j].b[p];
					}
					if(now==que[i].b){
						sum++;
					}
					now=que[i].a;
				}
			}
			
		}
		cout<<sum<<endl;
	}
	return 0;
}
