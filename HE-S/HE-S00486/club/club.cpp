#include<bits/stdc++.h>
using namespace std;
//vector<int>ans1;
//vector<int>ans2;
//vector<int>ans3;
//int zui;
struct cy{
long long m1,m2,m3;
int sc,qc,zb;
long long scz,qcz,zbz;
}a[100005];
int ansss;
int cmp1(cy x,cy y){
	return x.sc<=y.sc;
}
int cmp2(cy x,cy y){
	return x.scz<=y.scz;
}
long long f,s,t,fzc,f1,s1,t1;
int main(){

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long n,T;
	cin>>T;
	while(T--){
    bool flag=false;
	bool flag1=false;
	bool flag2=false;
		cin>>n;
//        ans1.clear();
//        ans2.clear();
//        ans3.clear();
		f=0;
		s=0;
		t=0;
		fzc=0;
		//zui=0;
		f1=0;
		s1=0;
		t1=0;
		ansss=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].m1>>a[i].m2>>a[i].m3;
			//int zui=max(a[i].m1,max(a[i].m2,a[i].m3));
			if(a[i].m1>=a[i].m2){
				if(a[i].m1>=a[i].m3){
					f++;
					f1++;
				   // ans1.push_back(zui);
				    a[i].sc=1;
				    a[i].scz=a[i].m1;
				    if(a[i].m2>a[i].m3){
				    	a[i].qc=2;
				    	a[i].qcz=a[i].m2;
				    	a[i].zb=3;
				    	a[i].zbz=a[i].m3;
				    }else{
				        a[i].qc=3;
						a[i].qcz=a[i].m3;
						a[i].zb=2;
						a[i].zbz=a[i].m2;	
					  }
					}
				
				else{
					t++;
					t1++;
				//	ans3.push_back(zui);
					a[i].sc=3;
					a[i].scz=a[i].m3;
					a[i].qc=1;
					a[i].qcz=a[i].m1;
					a[i].zb=2;
					a[i].zbz=a[i].m2;
				}
		    }
			else  if(a[i].m2>=a[i].m3){
				s++;
				s1++;
				//ans2.push_back(zui);
				a[i].sc=2;
				a[i].scz=a[i].m2;
				if(a[i].m1>a[i].m3){
				  a[i].qc=1;
				  a[i].qcz=a[i].m1;
				  a[i].zb=3;
				  a[i].zbz=a[i].m3;	
				  }
				  else{
				  	a[i].qc=3;
				  	a[i].qcz=a[i].m3;
				  	a[i].zb=1;
				  	a[i].zbz=a[i].m1;
				  }
				}else{
					t++;
					t1++;
					//ans3.push_back(zui);
					a[i].sc=3;
					a[i].scz=a[i].m3;
					a[i].qc=2;
					a[i].qcz=a[i].m2;
					a[i].zb=1;
					a[i].zbz=a[i].m1;
				}
	     }
		 
		//everybody都到了最想去的部门,有了第二选择，第三选择 
		//筛
		  stable_sort(a+1,a+1+n,cmp1);
		  stable_sort(a+1,a+1+n,cmp2);//ctrlc
		  if(f>n/2){
		     for(int g=1;g<=f-n/2;g++){
		     	if(a[g].qc==2)
		     	if(s<n/2&&(a[g].qcz<a[f-n/2+1].scz)){
		     	a[g].sc=2;
		     	a[g].scz=a[g].qcz;
		     	s++;
		     	s1++;
		     	f1--;
		     	if(a[g].qcz>a[f-n/2+1].scz){f++;
				 f1++;} 
	        }
	        else{
	        a[g].sc=a[g].zb;
			a[g].scz=a[g].zbz;
			t++;
			t1++;
			f1--;	
			}
		if(a[g].qc==3)if(t<n/2&&(a[g].qcz>a[f-n/2+1].scz)){
			a[g].sc=3;
			t++;
			t1++;
			f1--;
			a[g].scz=a[g].qcz;
				if(a[g].qcz>a[f-n/2+1].scz){
				f++;
				f1++;
			}
		}else{
			a[g].sc=2;
			a[g].scz=a[g].zbz;
			s++;
			s1++;
			f--;
		}
	   }
	        flag=true;
         }
         if(flag){
         sort(a+1,a+1+n,cmp1);
         sort(a+1,a+1+n,cmp2);
     }for(int g=f1+1;g<=s-n/2;g++){
    if(s>n/2&&(a[g].qcz>a[s-n/2+1].scz)){
		     
		     	if(a[g].qc==1)
		     	if(f<n/2){
		     	a[g].sc=1;
		     	a[g].scz=a[g].qcz;
		     	f++;
		     	s1--;
		     		if(a[g].qcz>a[s-n/2+1].scz){
					 s++;
					 s1++;
				}
	        }
	        else{
	        a[g].sc=a[g].zb;
			a[g].scz=a[g].zbz;
			t++;
			t1++;
			s1--;	
			}
		if(a[g].qc==3)if(t<n/2&&(a[g].qcz>a[s-n/2+1].scz)){
			a[g].sc=3;
			t++;
			t1++;
			s1--;
			a[g].scz=a[g].qcz;
				if(a[g].qcz>a[s-n/2+1].scz){
				s++;
				s1++;}
		}else{
			a[g].sc=1;
			a[g].scz=a[g].zbz;
			f++;
			f1++;
			s1--;
		}
	   }
	        flag1=true;
         }
      if(flag1){
         sort(a+1,a+1+n,cmp1);
         sort(a+1,a+1+n,cmp2);
	}//dz
	if(t>n/2){
		     for(int g=s1+1;g<=t-n/2;g++){
		     	if(a[g].qc==2)
		     	if(s<n/2&&(a[g].qcz>a[t-n/2+1].scz)){
		     	a[g].sc=2;
		     	a[g].scz=a[g].qcz;
		     	s++;
		     	s1++;
		     	t1--;
		     		if(a[g].qcz>a[f-n/2+1].scz){
					 t++;
					 t1++;}
	        }
	        else{
	        a[g].sc=a[g].zb;
			a[g].scz=a[g].zbz;
			f++;
			f1++;
			t1--;	
			}
		if(a[g].qc==1)if(f<n/2&&(a[g].qcz>a[t-n/2+1].scz)){
			a[g].sc=1;
			f++;
			f1++;
			t1--;
			a[g].scz=a[g].qcz;
				if(a[g].qcz>a[t-n/2+1].scz){
				t++;
				t1++;}
		}else{
			a[g].sc=2;
			a[g].scz=a[g].zbz;
			s++;
			s1++;
			t1--;
		}
	   }
	        flag2=true;
         }
           if(flag2){
         sort(a+1,a+1+n,cmp1);
         sort(a+1,a+1+n,cmp2);}
         for(int v=1;v<=n;v++){
         	ansss+=a[v].scz; 
		 }
		 cout<<ansss<<endl;
     }
	return 0;
}
