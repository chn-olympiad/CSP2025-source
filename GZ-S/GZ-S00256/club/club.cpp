//GZ-S00256 杨俊毅 遵义市南白初级中学 
#include <bits/stdc++.h>
using namespace std;
struct shuju{
	bool jiaruguo;
	long long manyidu;
};
shuju a1[100005],a2[100005],a3[100005];
bool cmp(shuju x,shuju y){
	return x.manyidu>y.manyidu;
}
int t;
long long n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
cin>>t;
while(t--){
	bool specialA=true,specialB=true;
	long long sum=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a1[i].manyidu>>a2[i].manyidu>>a3[i].manyidu;
		if(a2[i].manyidu!=0||a3[i].manyidu!=0)
		specialA=false;
		if(a3[i].manyidu!=0)
		specialB=false;	
		a1[i].jiaruguo=0;
		a2[i].jiaruguo=0;
		a3[i].jiaruguo=0;
	}
	int x1=n/2;
	int x2=n/2;
	int x3=n/2;
for(int i=1;i<=n;i++){
		if(specialA){
		sort(a1+1,a1+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			sum+=a1[i].manyidu;
		}
		cout<<sum<<endl;
		
		break;
	}
		if(specialB){
		sort(a2+1,a2+1+n,cmp);
		sort(a1+1,a1+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			sum+=max(a1[i].manyidu,a2[i].manyidu);
		}
		cout<<sum<<endl;
		
		break;
	}
	int maxn=max(max(a2[i].manyidu,a3[i].manyidu),a1[i].manyidu);
	if(a1[i].manyidu==maxn){
		if(x1!=0&&a1[i].jiaruguo==false&&a2[i].jiaruguo==false&&a3[i].jiaruguo==false){
			sum+=a1[i].manyidu;
			a1[i].jiaruguo=true;
			a2[i].jiaruguo=true;
			a3[i].jiaruguo=true;
			x1--;
		}
	}else if(a2[i].manyidu==maxn){
		if(x2!=0&&a1[i].jiaruguo==false&&a2[i].jiaruguo==false&&a3[i].jiaruguo==false){
			sum+=a2[i].manyidu;
			a1[i].jiaruguo=true;
			a2[i].jiaruguo=true;
			a3[i].jiaruguo=true;
			x2--;
		}
	}else if(a3[i].manyidu==maxn){
		if(x3!=0&&a1[i].jiaruguo==false&&a2[i].jiaruguo==false&&a3[i].jiaruguo==false){
			sum+=a3[i].manyidu;
			a1[i].jiaruguo=true;
			a2[i].jiaruguo=true;
			a3[i].jiaruguo=true;
			x3--;
		}
	} 
}
if(specialA==false&&specialB==false)
cout<<sum<<endl;
}
	
	return 0;
}
//燃尽了(不要爆0,谢谢CCF) 
