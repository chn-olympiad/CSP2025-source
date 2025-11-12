#include<iostream>
#include<cstring>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int b,a,c[101],x,y,xm,ym,m,e,p=1;
cin>>x>>y>>m;
e=x*y;
for(int j=0;j<e-1;j++){
 cin>>c[j];
}
for(int f=0;f<e-1;f++){//除自己以外其他人分数排名 
    for(int n=0;n<e-2;n++){
        if(c[n]<c[n+1]){
            a=c[n+1];
            c[n+1]=c[n];
            c[n]=a;
        }
    }
}
for(int g=0;g<e-1;g++){//判断自己排名 
	if(m<c[g]){
		p++;
	}
}
if(p%y!=0){//判断列数 
	xm=(p/y)+1;
}
if(p%y==0){
	xm=(p/y);
}
if(xm%2==0){//判断行数：如果列数是偶数 
	ym=y-(p%y-1);
	if(p%y==0){
		ym=1;	
	}

}
if(xm%2!=0){//判断行数：如果列数是奇数 
	ym=p%y;
	if(p%y==0){
		ym=y;
	}
} 
cout<<xm<<" "<<ym;
fclose(stdin);
fclose(stdout);
return 0;
}


