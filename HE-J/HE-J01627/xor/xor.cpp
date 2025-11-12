#include<bits/stdc++.h>
using namespace std;
const long long A=500005;
int n,B=0,num=0,sum=0;
long long a[A],k;
struct x{
	int start,end;
}b[A];
bool cmp(x a,x b){
	return a.end<b.end;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			b[B].start=i;
			b[B].end=i;
			B++;
		}
		for(int f=i+1;f<=n;f++){
			num=f;
			for(int j=i+1;j<=f;j++){
				num=num^a[j];
			}
			if(num==k){
				b[B].start=i;
				b[B].end=f;
				B++;
			}
			num=0;
		}
	}
	sort(b+0,b+B,cmp);
	int flag=b[0].end;
	for(int i=0;i<B;i++){
		if(flag<b[i+1].start){
			sum++;
			flag=b[i+1].end;
		}
	}
	if(B>0){
		sum++;
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
