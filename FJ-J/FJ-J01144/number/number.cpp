//csp-s rp++
#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int tong[15]={0};
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
		if(s[i]<='9'&&s[i]>='0')
			tong[s[i]-'0']++;
	for(int i=9;i>=0;i--){
		for(int j=1;j<=tong[i];j++)
			cout<<i;
	}	
	return 0;
}//Ô­Éñ£¬Æô¶¯
//sto czh
//sto gjh
//sto lhy
/*
RRRRRRR        PPPPPPP
RRRRRRRRR      PPPPPPPPP
RR     RR      PP	  PP	++	   ++	
RR     RR	   PP     PP	++     ++
RRRRRRRRR	   PPPPPPPPP  ++++++ ++++++
RRRRRRRRR	   PPPPPPPPP  ++++++ ++++++
RRRR 		   PP			++     ++
RRRRR		   PP			++     ++
RR RRR		   PP	
RR  RRR		   PP
RR   RRR	   PP
RR    RRR 	   PP 
*/  
