#include<bits\stdc++.h>
using namespace std;
//结构体 
struct stu{
	int a;
	int b;
	int c;
}; 
//变量与数组 
int t,n,sum;
int a1[5005];
int b2[5005];
int c3[5005];
int te[5005];
int at,bt,ct; 
stu p[10005];

void cz(){
	sum=0;
	for (int i=1;i<=n;i++){
		a1[i]=0;
		b2[i]=0;
		c3[i]=0;
		at=0;
		bt=0;
		ct=0;
		p[i].a=0;
		p[i].b=0;
		p[i].c=0;
	}
} 
//主函数 
int main(){
	freopen("club2.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++){
		cin>>n;
		for (int j=1;j<=n;j++){//首次分配 
			cin>>p[j].a>>p[j].b>>p[j].c;
			if (p[j].a>p[j].b&&p[j].a>p[j].c){
				a1[++at]=j;	
			}
			else if (p[j].a>p[j].b&&p[j].a>p[j].c){
				b2[++bt]=j;	
			}
			else{ 
				c3[++ct]=j;	
			}
		}
		for (int l=1;l<=at;l++){
			te[l]=a1[l];
		}
		if (at>n/2){//二次分配 
			int min=1000000000;
			int temp;
			while(at>n/2){
				for (int i=1;i<=at;i++){
					if(p[a1[i]].a<min){
						min=p[a1[i]].a;
						temp=a1[i];
					}
				}
				at--;
				if (p[temp].b>p[temp].c){
					b2[++bt]=temp;
				}
				else{
					c3[++ct]=temp;
				}		
			}
		}
		if (bt>n/2){
			int min=1000000000;
			int temp;
			while(bt>n/2){
				for (int i=1;i<=bt;i++){
					if(p[b2[i]].b<min){
						min=p[b2[i]].b;
						temp=b2[i];
					}
				}
				bt--;
				if (p[temp].a>p[temp].c){
					a1[++at]=temp;
				}
				else{
					c3[++ct]=temp;
				}		
			}
		}
		if (ct>n/2){
			int min=1000000000;
			int temp;
			while(ct>n/2){
				for (int i=1;i<=ct;i++){
					if(p[c3[i]].c<min){
						min=p[c3[i]].c;
						temp=c3[i];
					}
				}
				ct--;
				if (p[temp].b>p[temp].a){
					b2[++bt]=temp;
				}
				else{
					a1[++at]=temp;
				}		
			}
		}
		//加 
		for (int l=1;l<=at;l++){
			sum+=p[a1[l]].a;
		}
		for (int l=1;l<=bt;l++){
			sum+=p[b2[l]].b;
		}
		for (int l=1;l<=ct;l++){
			sum+=p[c3[l]].c;
		}
		
		cout<<sum<<endl;
		cz;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
