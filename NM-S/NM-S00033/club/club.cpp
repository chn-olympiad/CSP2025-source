          #include<bits/stdc++.h>
          using namespace std;
          int t; //有t组对象
		  int n; 
		  int m1;
		  int m2;
		  int m3;
		  int a1[99999];
		  int a2[99999];
		  int a3[99999];
		  int bt1;
		  int bt2;
		  int bt3;
		  int btzzz;
		  int main(){
            cin>>t;
            cin>>n;
            for(int o=1; o<=t; o++){
            	  for(int i=1; i<=n; i++){
            	cin>>m1>>m2>>m3;
                if(m1-m2>0){
                	if(m1-m3>0){
                		a1[i]=m1;
					}else{
						a3[i]=m3;
					}
				}else{
					if(m2-m3>0){
						a2[i]=m2;
					}else{
						a3[i]=m3;
					}
				}
			}
			for(int i=1; i<=n; i++){
				sort(a1[i],a1[n]);                      //a1的前n/2的满意度和 
				for(int a; a<=n/2-1; a++){
					int q=a1[n-a];
					for(int y=1; y<=n/2-1; y++){
						int a1q[99999];
						a1q[y]=q;
					}
					
				}
				bt1=a1[n]+a1q;
			}
			for(int i=1; i<=n; i++){
				sort(a2[i],a2[n]);
				for(int a; a<=n/2-1; a++){
					int q=a2[n-a];
					for(int y=1; y<=n/2-1; y++){
						int a2q[99999];
						a2q[y]=q;
					}
					
				}
				bt2=a2[n]+a2q;
			}
			for(int i=1; i<=n; i++){
				sort(a3[i],a3[n]);
				for(int a; a<=n/2-1; a++){
					int q=a3[n-a];
					for(int y=1; y<=n/2-1; y++){
						int a3q[99999];
						a3q[y]=q;
					}
					
				}
				bt3=a3[n]+a3q;
			}
			btzzz=bt1+bt2+bt3;
			cout<<btzzz<<endl;
			}
		  	return 0;
		  }
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
		  
