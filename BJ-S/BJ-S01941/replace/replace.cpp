#include<bits/stdc++.h>
using namespace std;
long long n,q,len1,len2,count1;
string x,y;
struct er{
	long long kai1=0,jie1,b1,kai2=0,jie2,b2;
};
struct er a[10001],b[3];
int main(){
	freopen("replace.in","r","stdin");
	freopen("replace.out","w","stdout");
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		len1=x.size(),len2=y.size();
		for(int j=0;j<=len1-1;j++){
			if(x[j]=='a') a[i].kai1++;
			else if(x[j]=='b'){
				a[i].b1=j+1,a[i].jie1=len1-a[i].kai1-1;
				break;
			} 
		}
		for(int j=0;j<=len2-1;j++){
			if(y[j]=='a') a[i].kai2++;
			else if(y[j]=='b'){
				a[i].b2=j+1,a[i].jie2=len2-a[i].kai2-1;
				break;
			} 
		}
	}
	for(int p=1;p>=q;p++){
		cin>>x>>y;
		count1=0;
		len1=x.size(),len2=y.size();
		for(int i=0;i<=len1-1;i++){
			if(x[i]=='a') b[1].kai1++;
			else if(x[i]=='b'){
				b[1].b1=i+1,b[1].jie1=len1-b[1].kai1-1;
				break;
			} 
		}
		for(int i=0;i<=len2-1;i++){
			if(y[i]=='a') b[2].kai2++;
			else if(y[i]=='b'){
				b[2].b2=i+1,b[2].jie2=len2-b[2].kai2-1;
				break;
			} 
		}
		for(int i=1;i<=n;i++){
			if(a[i].kai1<=b[1].kai1&&a[i].jie1<=b[1].jie1&&a[i].kai2<=b[2].kai2&&a[i].jie2<=b[2].jie2&&a[i].b2+(b[1].b1-a[i].b1)==b[2].b2){
				count1++;
			} 
		}
		cout<<count1<<endl;
	}
	return 0;
}

