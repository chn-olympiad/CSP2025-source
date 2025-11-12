#include<bits/stdc++.h> 
using namespace std;
int a,m[100001],cnt=0;
void f(int num,int chang){
	if(num<=a){
		if(chang>2*m[num]&&num>=3){
			cnt++;
		} 
		for(int i=num;i<a;i++){
			f(i+1,chang+m[i+1]);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&a);
	for(int i=1;i<=a;i++){
		scanf("%d",&m[i]);
	} 
	sort(m+1,m+a+1);
	f(0,0);
	printf("%d",cnt%998244353);
	fclose(stdin);fclose(stdout);
	return 0;
}
