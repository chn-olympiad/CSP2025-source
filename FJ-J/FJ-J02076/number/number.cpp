#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[1000];
	char b[10]={'0','1','2','3','4','5','6','7','8','9'};
	int sum=0;
	int zh[10]={0,1,2,3,4,5,6,7,8,9};
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		for(int x=0;x<=9;x++){
			if(s[i]==b[x]){
				a[sum]=zh[x];
				sum++;
				break;
			}
		}
	}
	int c=sum,d=0,f=1;
	for(int z=9;z>=0;z--){
		for(int y=0;y<sum;y++){
			f=1;
			for(int i=1;i<c;i++){
				f=f*10;
			}
			if(a[y]==z){
				d=d+z*f;
				c--;
				
			}
		}
	}
 	cout<<d;
	return 0;
}
