//ÄãºÃ 
#include<bits/stdc++.h>
using namespace std;

const int N = 100000;
 
int n, t;

int kl = 99999;
int mb = 0;

int a1[N],a[N],a3;
int b1[N],b[N],b3;
int c1[N],c[N],c3;

bool s[N];

void abc()
{
	int jma = n / 2;
	for(int i = 0;i < n;++i)
	{
		if(a1[i] > b1[i] && b1[i] > c1[i] && s[i] == false)
		{
			if(a3 < jma && s[i] == false)
			{
				a[i] = a1[i];
				s[i] =true;
				a3++;
			}
			else if(a3 >= jma && s[i] == false)
			{
				kl = 99999;
				for(int fto = 0 ;fto < jma ;fto++)
				{
					if(a[fto] < kl)
					{
						kl = a[fto];
						mb = fto;
					}
				}
				if(a1[i] > a[mb])
				{
					a[mb] = a1[i];
					s[mb] = false;
					s[i] = true;
				}
			}
			
			
			
			if(b3 < jma && s[i] == false)
			{
				b[i] = b1[i];
				s[i] = true;
				b3++;
			}
			else if(b3 >= jma && s[i] == false)
			{
				kl = 99999;
				for(int fto = 0 ;fto < jma ;fto++)
				{
					if(b[fto] < kl)
					{
						kl = b[fto];
						mb = fto;
					}
				}
				if(a1[i] > a[mb])
				{
					b[mb] = b1[i];
					s[mb] = false;
					s[i] = true;
				}
			}
			
			
			
			if(c3 < jma && s[i] == false)
			{
				c[i] = c1[i];
				s[i] = true;
				c3++;
			}
			else if(c3 >= jma && s[i] == false)
			{
				kl = 99999;
				for(int fto = 0 ;fto < jma ;fto++)
				{
					if(c[fto] < kl)
					{
						kl = c[fto];
						mb = fto;
					}
				}
				if(c1[i] > c[mb])
				{
					c[mb] = c1[i];
					s[mb] = false;
					s[i] = true;
				}
			}
		}
		
		/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		
		if(a1[i] < b1[i] && b1[i] > c1[i] && a1[i] > c1[i] && s[i] == false)
		{
			if(b3 < jma && s[i] == false)
			{
				b[i] = b1[i];
				s[i] = true;
				b3++;
			}
			else if(b3 >= jma && s[i] == false)
			{
				kl = 99999;
				for(int fto = 0 ;fto < jma ;fto++)
				{
					if(b[fto] < kl)
					{
						kl = b[fto];
						mb = fto;
					}
				}
				if(a1[i] > a[mb])
				{
					b[mb] = b1[i];
					s[mb] = false;
					s[i] = true;
				}
			}
			
			
			
			if(a3 < jma && s[i] == false)
			{
				a[i] = a1[i];
				s[i] =true;
				a3++;
			}
			else if(a3 >= jma && s[i] == false)
			{
				kl = 99999;
				for(int fto = 0 ;fto < jma ;fto++)
				{
					if(a[fto] < kl)
					{
						kl = a[fto];
						mb = fto;
					}
				}
				if(a1[i] > a[mb])
				{
					a[mb] = a1[i];
					s[mb] = false;
					s[i] = true;
				}
			}
			
			if(c3 < jma && s[i] == false)
			{
				c[i] = c1[i];
				s[i] = true;
				c3++;
			}
			
			
			
			else if(c3 >= jma && s[i] == false)
			{
				kl = 99999;
				for(int fto = 0 ;fto < jma ;fto++)
				{
					if(c[fto] < kl)
					{
						kl = c[fto];
						mb = fto;
					}
				}
				if(c1[i] > c[mb])
				{
					c[mb] = c1[i];
					s[mb] = false;
					s[i] = true;
				}
			}
		}
		
		/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		
		
		if(a1[i] < b1[i] && b1[i] < c1[i] && s[i] == false)
		{
			if(c3 < jma && s[i] == false)
			{
				c[i] = c1[i];
				s[i] = true;
				c3++;
			}
			
			
			
			else if(c3 >= jma && s[i] == false)
			{
				kl = 99999;
				for(int fto = 0 ;fto < jma ;fto++)
				{
					if(c[fto] < kl)
					{
						kl = c[fto];
						mb = fto;
					}
				}
				if(c1[i] > c[mb])
				{
					c[mb] = c1[i];
					s[mb] = false;
					s[i] = true;
				}
			}
			
			
			
			if(b3 < jma && s[i] == false)
			{
				b[i] = b1[i];
				s[i] = true;
				b3++;
			}
			else if(b3 >= jma && s[i] == false)
			{
				kl = 99999;
				for(int fto = 0 ;fto < jma ;fto++)
				{
					if(b[fto] < kl)
					{
						kl = b[fto];
						mb = fto;
					}
				}
				if(a1[i] > a[mb])
				{
					b[mb] = b1[i];
					s[mb] = false;
					s[i] = true;
				}
			}
			
			
			
			if(a3 < jma && s[i] == false)
			{
				a[i] = a1[i];
				s[i] =true;
				a3++;
			}
			else if(a3 >= jma && s[i] == false)
			{
				kl = 99999;
				for(int fto = 0 ;fto < jma ;fto++)
				{
					if(a[fto] < kl)
					{
						kl = a[fto];
						mb = fto;
					}
				}
				if(a1[i] > a[mb])
				{
					a[mb] = a1[i];
					s[mb] = false;
					s[i] = true;
				}
			}
		}
	}	
	for(int i = 0;i < n;++i)
	{
		if(s[i] == false)
		{
			abc();
		}
	}
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i = 0;i < n;++i)
		{
			cin>> a1[i] >> b1[i] >> c1[i];
		}
		
		a3=0,b3=0,c3=0;
		
		abc();		
	}
	
	return 0;
}
//ÔÙ¼û 
