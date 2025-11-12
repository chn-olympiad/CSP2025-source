#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],k=1,r[1000010];
void px(int s,int e){
	if(s==e) return ;
	int mid=(s+e)/2,d=1,i=s,j=mid+1;
	px(s,mid);
	px(mid+1,e);
	
	while(i<=mid && j<=e){
		if(a[i]<=a[j]){
			r[d++]=a[i++];
		}
		else{
			r[d++]=a[j++];
		}
	}
	while(i<=mid){
		r[d++]=a[i++];
	}
	while(j<=e){
		r[d++]=a[j++];
	}
	d=1;
	for(int i=s;i<=e;i++) a[i]=r[d++];
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[k]=s[i]-'0';
			k++;
		}
	}
	px(1,k-1);
	for(int i=k-1;i>=1;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


