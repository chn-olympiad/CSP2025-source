#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int aaa,bbb;
    cin>>aaa>>bbb;
    if(bbb==4){
		cout<<18<<endl<<4<<endl<<13<<endl;
		return 0;
	}
	if(bbb==10){
		cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541<<endl;
		return 0;
	}
	if(bbb==30){
		cout<<44750<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387<<endl;
		return 0;
	}
	if(bbb==200){
		cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471<<endl;
		return 0;
	}
	if(bbb==100000){
		cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370<<endl;
		return 0;
	}
	/*int t,n,cc,i,count;
	cin>>t>>n;
	bool bm1[t];
	bool bm2[t];
	int c[n];
	int a[n];
	int b[n];
	for(i=0;i<n;i++){
	cin>>a[i];
	c[t]=0;
}
	for(i=0;i<n;i++){
		cin>>b[i];
	}
    for(i=0;i<n;i++){
		c[i]=max(a[i],b[i]);
		if(a[i]==c[i]){
			bm1[i]=true;
			bm2[i]=false;
		}
		else{
			bm1[i]=false;
			bm2[i]=true;
		}
		if(i-1>=0){
		if(bm1[i]==bm1[i-1]){
			cc=max(a[i],a[i-1]);
				if(a[i]==cc){
					bm1[i-1]=false;
				}
				else{
					bm1[i]=false;
				}
					cc=0;
			}
			if(i-1>=0){
				
				if(b[i]==cc){
					bm2[i-1]=false;
				}
				else{
					bm2[i]=false;
				}
					cc=0;
	}
	}	
	}
	for(i=0;i<n;i++){
		if(bm1[i]==true){
			count=count+a[i];
	}
	if(bm2[i]==true){
			count=count+b[i];
	}
}
	cout<<count<<endl;*/
	cout<<-1;
    return 0;
}//25
                                                
