#include<bits/stdc++.h>
using namespace std;
struct node{
	int yi;
	int er;
	int san;
	int bianhao;
	int zuida;
	int aihao;
};
int n,num,t;
node a[100100];
bool emp(node x,node y){
	if(x.aihao==y.aihao){
		return x.zuida>y.zuida;
	}else{
		return x.aihao<y.aihao;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int b,c,z;
			cin>>a[i].yi>>a[i].er>>a[i].san;
			b=a[i].er;
			c=a[i].san;
			z=a[i].yi;
			a[i].zuida=max(max(b,c),z);
			a[i].bianhao=i;
			if(b>c){
				a[i].zuida=b;
				a[i].aihao=2;
			}else{
				a[i].zuida=c;
				a[i].aihao=3;
			}
			if(a[i].zuida<z){
				a[i].zuida=z;
				a[i].aihao=1;
			}
		}
		if(n==2){
			num=max(num,a[1].yi+a[2].er);
			num=max(num,a[1].yi+a[2].san);
			num=max(num,a[1].er+a[2].yi);
			num=max(num,a[1].er+a[2].san);
			num=max(num,a[1].san+a[2].yi);
			num=max(num,a[1].san+a[2].er);
			cout<<num<<endl;
			continue;
		}
		sort(a+1,a+1+n,emp);
		int sum=0,az[7];
		for(int i=1;i<=n/2;i++){
			if(a[i].aihao!=1){
				break;
			}
			num+=a[i].zuida;
			sum=i;	
		}
		for(int i=1;i<=n/2;i++){
			if(a[sum+1].aihao!=2)
				break;
			sum++;
			num+=a[sum].zuida;	
		}
		for(int i=1;i<=n/2;i++){
			if(a[sum+1].aihao!=3){
				break;
			}
			sum=sum+1;
			num+=a[sum].zuida;
		}
		cout<<num<<endl;	
	}
	return 0;
}
