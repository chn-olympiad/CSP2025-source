/*
 * seat.cpp
 * 
 * Copyright 2025 noi <noi@noi-virtual-machine>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */ 



#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat","w",stdout);
	int x;
	int y;
	int n;
	int mx=0;
	int mn=0;
	cin>>x>>y;
	n=x*y;
	int a[n];
	for(int i=0;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=n;i++)
	{
		if(mx<a[i])
		mx=a[i];
	}
	if(mx==a[0])
	cout<<1<<' '<<1;
	for(int i=0;i<=n;i++)
	{
		if(mn>a[i])
		mn=a[i];
	}
	if(mn==a[0])
	cout<<x<<' '<<y;
	return 0;
}

