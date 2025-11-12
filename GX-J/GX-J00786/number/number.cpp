#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen ("number.in","w","number.strin");
	//freopen ("number.ou","r","number.strout");
	double s;
	cin>>s;
	int a=s.size;
	int b[10005]=" ";
	for(int i=0; i<=a;i++ ){
		int ans=0;
		
		if(s[i]=="1" ||"2"||"3"||"4"||"5" ||"6"||"7"||"8"||"9")
		    b+=s[i];
		    ans++;
		    
		}
		
        if(ans==1){
				cout<<b;
				}
		else{
			for(int j=0;j<=ans;j++)
			    b[j]==b[j+1];
			    int d=0;
			    b[j]=0;
			    if(b[j]>b[j=1]){
				    cout<<b[j]<<;
				}
			    
			
			}
		
		
		
	
	
	
	
	return 0;
}
