#include<bits/stdc++.h>
using namespace std;
int n,k,a[10000],in[10000][3],sumin;
int Longstr(string a,int b){
	return a[b];
}
long long Second(int a){
	if(a==1||a==0)return a;
	return a%2+Second(a/2)*10;
}
int max(int ai,int bi){
	return ai>bi?ai:bi;
}
int Xor(int ai,int bi){
	int l1=sizeof(Second(ai)),l2=sizeof(Second(bi));
	if(l2>l1)return Xor(bi,ai);
}
int Suma(int ai,int bi){
	int temp=0;
	for(int i=ai;i<=bi;i++)temp+=Xor(temp,a[i]);
	return temp;
}
int main(){
	freopen("xor2.in","r",stdin);
	freopen("xor2.ans","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		int j;
		for(j=i;Suma(i,j)<k;j++);
		if(Suma(i,j)==k){
			in[sumin][0]=i;
			in[sumin][1]=j;
			sumin++;
			i=j;
		}
	}
	printf("%d",sumin+1);
	return 0;
}
