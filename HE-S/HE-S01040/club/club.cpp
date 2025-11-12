#include <bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int a1;
	int a2;
	int a3;
	int f=0;
	int m;
	int ml;
};
bool p1(node a,node b){
	return a.a1>b.a1;
}
bool p2(node a,node b){
	return a.a2>b.a2;
}
bool p3(node a,node b){
	return a.a2>b.a2;
}
int z1(node a[]){
	int ent=0;
	sort(a,a+n,p1);
	for(int i=0;i<n/2;i++){
		ent+=a[i].a1;
	}for(int i=n/2;i<n;i++){
		ent+=a[i].a2;
	}return ent;
}
int z2(node a[]){
	int ent=0;
	sort(a,a+n,p2);
	for(int i=0;i<n/2;i++){
		ent+=a[i].a2;
	}for(int i=n/2;i<n;i++){
		ent+=a[i].a1;
	}
	return ent;
}
 z3(node a[]){
	int ent=0;
	sort(a,a+n,p3);
	for(int i=0;i<n/2;i++){
		ent+=a[i].a3;
	}return ent;
}
int people[4]={0};
int l1,l2,l3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	node a[10100];
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>n;
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&a[i].a1,&a[i].a2,&a[i].a3);
			a[i].m=max(max(a[i].a1,a[i].a2),a[i].a3);
		}if(n>=200){
			int h1=z1(a),h2=z2(a);
			if(h2>h1){
				cout<<h2;
			}else{
				cout<<h1;
			}
		}else if(n==2){
			int op[6],qq=0;
			op[0]=a[0].a1+a[1].a2;
			op[1]=a[0].a1+a[1].a3;
			op[2]=a[0].a2+a[1].a1;
			op[3]=a[0].a2+a[1].a3;
			op[4]=a[0].a3+a[1].a1;
			op[5]=a[0].a3+a[1].a2;
			for(int i=0;i<6;i++){
				qq=max(op[i],qq);
			}cout<<qq;
		}else if(n==4){
			int op[1000],qq=0,ent=0;
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					for(int q=0;q<3;q++){
						for(int p=0;p<3;p++){
							if(i==j&&j==q||j==q&&q==p||i==q&&p==q||i==j&&j==p){
								continue;
							}else{
								int l1,l2,l3,l4; 
								if(i==0)
								l1=a[0].a1;
								else if(i==1)
								l1=a[0].a2;
								else
								l1=a[0].a3;
								
								if(j==0)
								l2=a[1].a1;
								else if(j==1)
								l2=a[1].a2;
								else
								l2=a[1].a3;
								
								if(q==0)
								l3=a[2].a1;
								else if(q==1)
								l3=a[2].a2;
								else
								l3=a[2].a3;
								
								if(p==0)
								l4=a[3].a1;
								else if(p==1)
								l4=a[3].a2;
								else
								l4=a[3].a3;
								
								op[ent]=l1+l2+l3+l4;
								ent++;
							}
						}
					}
				}
			}for(int i=0;i<=ent;i++){
				qq=max(op[i],qq);
			}cout<<qq;
		}else{
			int ent=0;
			for(int i=0;i<n;i++){
				ent+=max(max(a[i].a1,a[i].a2),a[i].a3);
			}cout<<ent;
		}
		cout<<endl;
	}
	return 0;
}
