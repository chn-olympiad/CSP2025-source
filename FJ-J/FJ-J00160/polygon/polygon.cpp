#include<bits/stdc++.h>
using namespace std;
int n,a[100000],sum;
int Ways(int t){
	if(t<3)return 0;
	int ch[10000],temp=0;
	for(ch[0]=0;ch[0]<n;ch[0]++){
		for(ch[1]=ch[0]+1;ch[1]<n;ch[1]++){
			for(ch[2]=ch[1]+1;ch[2]<n;ch[2]++){
				int sumch=0;
				for(int a=0;a<3;a++)sumch+=ch[a];
				if(sumch>ch[2]*2)temp++;
			}
		}
	}
	return temp;
}
int main(){
	freopen("polygon1.in","r",stdin);
	freopen("polygon1.ans","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);
	for(int num=3;num<=n;num++)sum+=Ways(num);
	printf("%d",sum);
	return 0;
} 
