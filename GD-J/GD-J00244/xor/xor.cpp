#include<bits/stdc++.h>
using namespace std;
struct aabb{
	int aaa;
	int bbb;
}abt[500005];
bool cmp(aabb e,aabb ec){
	return e.bbb<ec.bbb; 
}
int a[500005],b,k,n,m,t,z,js;
int ab[40],bb[40],zz=1,maax;
int yh(int at,int bt){
	//cout<<at<<"!"<<bt;
	for(int i=0;i<=39;i++){
		ab[i]=0;bb[i]=0;
	}
	maax=0;zz=1;t=0;
	for(int i=0;at!=0;i++){
		ab[i]=at%2;
		at/=2;
		maax=i;
	}
	int maaax=0;
	for(int i=0;bt!=0;i++){
		bb[i]=bt%2;
		bt/=2;
		maaax=i;
	}
	for(int i=0;i<=max(maax,maaax);i++){
		t+=zz*((ab[i]+bb[i])%2);
		zz*=2;
	}
	return t;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int z=0;
		for(int j=i;j<=n;j++){
			//cout<<"a"<<z<<"b"<<a[j]<<" "<<yh(z,a[j])<<" ";
			z=yh(z,a[j]);
			if(z==k){
				abt[js].aaa=i;
				abt[js].bbb=j;
				//cout<<abt[js].aaa<<" "<<abt[js].bbb;
				js++;
				break;
			}
		}
		//cout<<endl;
	}
	sort(abt,abt+js,cmp);
	t=0;m=0;
	for(int i=0;i<=js;i++){
		if(abt[i].aaa>t){
			m++;
			t=abt[i].bbb;
		}
	}
	cout<<m;
	return 0;
}
