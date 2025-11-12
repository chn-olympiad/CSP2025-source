/*#include<iostream>
#include<cstdio>
using namespace std;
int n,m,nm,tmp,num,r,ans;//nm=n*m
int y,x;
int cj[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm=n*m;
	cin>>r;
	cj[r]++;
	for(int i=1;i<nm;i++){
		cin>>tmp;
		cj[tmp]++;
	}
	for(int i=100;i>=0;i--){
		//tiao shi dai ma
		//cout<<i;
		//zhe li mei wen ti
		if(cj[i]!=0){
			num++;
		}
		if(i==r){
                        break;
                }
	}
	//jue dui shi zhe li de wen ti
	x=num%n+1;
	y=num/n+1;
	if(num%n==0){
		y--;
	}
	if(x%2==0){
		y=n-y+1;
	}
	cout<<y<<" "<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}*///hao ba gai ban de ye xing
//wo jiu bu xin le
#include<iostream>
#include<cstdio>
using namespace std;
int n,m,nm,tmp,num,r,ans;//nm=n*m
int y=1,x=1;
int cj[105];
int main(){
        freopen("seat.in","r",stdin);
        freopen("seat.out","w",stdout);
        cin>>n>>m;
        nm=n*m;
        cin>>r;
        cj[r]++;
        for(int i=1;i<nm;i++){
                cin>>tmp;
                cj[tmp]++;
        }
        for(int i=100;i>=0;i--){
                //tiao shi dai ma
                //cout<<i;
                //zhe li mei wen ti
                if(cj[i]!=0){
                        num++;
                }
                if(i==r){
                        break;
                }
        }
        //jue dui shi zhe li de wen ti
        for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i%2==0){
				y--;	
			}
			else{
				y++;
			}
			num--;
			if(num==0){
				x+=(y/n);
				y%=n;
				y++;
				cout<<x<<" "<<y;
			}
		}
		x++;
	}
        fclose(stdin);
        fclose(stdout);
        return 0;
}
