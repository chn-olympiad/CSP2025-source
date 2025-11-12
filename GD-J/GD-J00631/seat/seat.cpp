#include<bits/stdc++.h>
#define int long long
using namespace std;
inline void read(int &x){
	char ch=0;
	bool flag=false;
	x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-') flag=true;
		ch=getchar();
	}
	if(flag)
	while(ch>='0'&&ch<='9')
	x=x*10-(ch-'0'),ch=getchar();
	else
	while(ch>='0'&&ch<='9')
	x=x*10+(ch-'0'),ch=getchar();
}
inline void write(int x){
	bool flag=false;
	if(x<0) flag=true;
	if(flag) putchar('-');
	static int sta[40];
	int top=0;
	do{
		sta[top++]=x%10;
		x/=10;
	}while(x);
	if(flag)
	while(top) putchar('0'-sta[--top]);
	else
	while(top) putchar('0'+sta[--top]);
}
int n,m;
int R,a[105],No_R;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","r",stdout);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	read(n),read(m);
	read(R),a[1]=R;
	for(int i=2;i<=n*m;i++)
	read(a[i]);
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>0;i--)
	if(a[i]==R) No_R=n*m-i+1;
	int b=No_R/(2*n)+1;
	if(No_R%(2*n)==0){
		write(b*2),putchar(' '),putchar('1');
		return 0;
	}
	int c=No_R%(2*n);
	if(c<=n)
	{
		write(b*2-1),putchar(' '),write(c);
	}
	else{
		write(b*2),putchar(' '),write(n-(c-n-1));
	}
	return 0;
}
//GD-J00631
//AK IOI
/*
IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
						A
					   A A
					  A   A
					 A     A
					A       A
				   A         A
				  A           A
				 A             A
				A               A
			   A                 A
			  A                   A
			 A                     A
			A                       A
		   A                         A
		  A                           A
		 A                             A
		A                               A
	   A                                 A
	  A                                   A
	 AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
	A                                       A
   A                                         A
  A                                           A
 A                                             A
A                                               A					
K			            K								
K		              K								   
K		            K									  
K                 K                                   
K               K                                    
K			  K
K	        K
K	      K
K	    K
K	  K
K   K
K K
KK
K K
K   K
K	  K
K       K
K         K
K           K
K             K
K               K
K                 K
K                   K
K                     K
K                        K
IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
					    O
		  O      O           O       O
	    O                                O 
     O                                      O
   O                                          O
  O                                            O
 O                                               O
O                                                 O
O                                                 O
O                                                  O
O                                                  O
 O                                               O
  O                                            O
   O                                          O
	  O O                                O O
		  O                           O
			  O O          O    O
					    O
IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
						I
IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
*/
