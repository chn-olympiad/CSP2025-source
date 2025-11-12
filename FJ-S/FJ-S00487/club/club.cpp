#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club,in","r",stdin);
freopen("club.out","w",stdout);
	int xunhuan;//循环次数 
	cin>>xunhuan;
	for(int wuyong=0;wuyong<xunhuan;wuyong++){
		int zs=0;//总数 
    cin>>zs;
       int aa[zs+5][4],a[zs+5][4],b1[zs+5][4],b2[zs+5][4],b3[zs+5][4],b1max,b2max,b3max,c[zs+5],ans,people1,people2;//a喜好，b志愿 c排序  
        for(int i=0;i<zs;i++){
        	for(int j=0;i<zs;i++){
    	    cin>>a[j][1]>>a[j][2]>>a[j][3];
    	    aa[j][1]=a[j][1]-a[j][2];
    	    aa[j][2]=a[j][2]-a[j][3];
    	    aa[j][3]=a[j][1]-a[j][3];
	        }
	   
        }
        people1=zs/2;
        people2=zs/2;
       for(int k=0;k<zs;k++){
         	if(max(aa[k][1],-aa[k][1])>=max(max(aa[k][2],-aa[k][2]),max(aa[k][3],-aa[k][3]))){
         	if (aa[k][1]>-aa[k][1]){
         		b1[k][2]=aa[k][1];
         		b1max++;
			 }else{
			 	b2[k][1]=aa[k][2];
         		b2max++;
			 }}else if(max(aa[k][2],-aa[k][2])>=max(max(aa[k][1],-aa[k][1]),max(aa[k][3],-aa[k][3]))){
			 
         	if (aa[k][2]>-aa[k][2]){
         		b2[k][3]=aa[k][2];
         		b2max++;
			 }else{
			 	b3[k][2]=aa[k][3];
         		b3max++;
			 }}else{
			 if (aa[k][3]<-aa[k][3]){
         		b1[k][3]=aa[k][1];
         		b1max++;
			 }else{
			 	b3[k][1]=aa[k][3];
         		b3max++;
			 }
	       }
		   }
		    sort(b1[0][0],b1[0][b1max]);
		    for(int l=0;l>zs/2;l++){
		    ans=ans+b1[b1max-l][2]+b1[b1max-l][3];
			b1[b1max-l][2]=0;
			b1[b1max-l][3]=0;
			b1max--;
			people1--;	
			}//1组 
		    for(int k=0;k<b1max;k++){
		    	if(b1[k][2]!=0){
		    	b2[k][2]=aa[k][2];
         		b2max++;
				}else{
					b3[k][3]=aa[k][3];
         		b3max++;
				}
	       }
		    
		  sort(b2[0][0],b2[0][b2max]);
		    for(int l=0;l>zs/2;l++){
		    ans=ans+b2[b2max-l][1]+b2[b2max-l][3]+b2[b2max-l][2];
			b2[b2max-l][1]=0;
			b2[b2max-l][2]=0;
			b2[b2max-l][3]=0;
			b2max--;
			people2--;
		  
	        }
	          for(int k=0;k<b1max;k++){
		    	if(b2[k][2]!=0){
		    ans=ans+b2[k][2]+b2[k][3];
		    b3max--;
				}else{
				b3[k][3]=aa[k][3];
         		b3max++;
				}
	       }
			  sort(b3[0][0],b3[0][b3max]);
		    for(int l=0;l>zs/2;l++){
		    ans=ans+b3[b3max-l][2]+b3[b3max-l][1]+b3[b3max-l][3];
			b3[b3max-l][1]=0;
			b3[b3max-l][2]=0;
			b3[b3max-l][3]=0;
			b3max--;
			}
			if(b3max!=0){
				for(int k=0;k<b1max;k++){
				if(people1!=0,people2=0)ans=ans+a[k][1]; 
			else	if(people2!=0,people1=0)ans=ans+a[k][2];
			else if(a[k][1]>=a[k][2]){
				people1--;
			ans=ans+a[k][1]; }
			else {
			ans=ans+a[k][2];
			people2--;
			}
			}			 
			}
			cout<<ans<<endl;
			 ans=0;
	}
	return 0;
	}
	
