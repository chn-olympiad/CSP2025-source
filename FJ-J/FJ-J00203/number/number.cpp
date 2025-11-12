#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string n ;
	cin >> n ;
	int number[n.size()] = {} ;
	int shu = 0 ;
	int that = 0 ;
	for(int i = 0 ; i < n.size() ; i++ )
	{

		if( n[i] == '0' )
		{
			number[that] = 0 ;
			shu++ ;
			that++ ;
		}
		if( n[i] == '1' )
		{
			number[that] = 1 ;
			shu++ ;
			that++ ;
		}
		if( n[i] == '2' )
		{
			number[that] = 2 ;
			shu++ ;
			that++ ;
		}
		if( n[i] == '3' )
		{
			number[that] = 3 ;
			shu++ ;
			that++ ;
		}	
		if( n[i] == '4' )
		{
			number[that] = 4 ;
			shu++ ;
			that++ ;
		}
		if( n[i] == '5' )
		{
			number[that] = 5 ;
			shu++ ;
			that++ ;
		}
		if( n[i] == '6' )
		{
			number[that] = 6 ;
			shu++ ;
			that++ ;
		}
		if( n[i] == '7' )
		{
			number[that] = 7 ;
			shu++ ;
			that++ ;
		}
		if( n[i] == '8' )
		{
			number[that] = 8 ;
			shu++ ;
			that++ ;
		}
		if( n[i] == '9' )
		{
			number[that] = 9 ;
			shu++ ;
			that++ ;
		}
	}
	
	
	int CCS = 0 ;
	
	for(int i = 0 ; i < shu ; i++ )
	{
		for(int j = 0 ; j < shu ; j++ )
		{
			if( number[j] < number [j+1] )
			{
				int a = number[j] ;
				number[j] = number[j+1] ;
				number[j+1] = a ;
			}
		}
	}
	
	for(int i = 0 ; i < shu ; i++ ) 
	{
		cout << number[i] ;
	}
	

	return 0;
}
