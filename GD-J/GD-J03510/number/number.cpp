#include<bits/stdc++.h>
using namespace std;
string s1;
int a[1000005];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	int b=0;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			a[b]=s1[i]-'0';
			b++;
		}
	}//找数字 
	while (b>0){
		int maxn=-1,maxp=-1;
		for(int i=0;i<b;i++){
			if(maxn<a[i]){
			maxn=a[i];
			maxp=i;
			}
		}
		int r=a[b-1];
		a[maxp]=r;
		b--;
		cout<<maxn;	
	}//幽默遍历最大值 
	return 0;
} 
